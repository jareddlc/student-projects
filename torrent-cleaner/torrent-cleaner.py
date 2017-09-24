import glob
import os
import Tkinter
import tkFileDialog
import tkMessageBox
import sys
import bencode
import hashlib
import StringIO

def selectDir():
        dupe = 0;
        dirname = tkFileDialog.askdirectory(parent=app,initialdir="/",title='Please select a directory')
        if len(dirname ) > 0:
                print "Directory Selected: %s" % dirname
                #tkMessageBox.showinfo("Selected Directory", dirname)
        os.chdir(dirname)
        for files in glob.glob("*.torrent"):
                temp = open(files, 'rb')
                data = temp.read()
                metainfo = bencode.bdecode(data)
                info = metainfo['info']
                temp.close()
                #print temp.name +" = "+ hashlib.sha1(bencode.bencode(info)).hexdigest()+".torrent"
                if temp.name != (hashlib.sha1(bencode.bencode(info)).hexdigest()+".torrent"):
                        try:
                                os.rename(temp.name, hashlib.sha1(bencode.bencode(info)).hexdigest() +".torrent")
                        except OSError:
                                dupe += 1
                                print "Duplicate: " + str(dupe)
                #print hashlib.sha1(bencode.bencode(info)).hexdigest()
        tkMessageBox.showinfo("Torrent Renamer", "Batch Complete!\nDuplicates found: " + str(dupe))

def selectUDP():
        udp = 0
        track = []
        dirname = tkFileDialog.askdirectory(parent=app,initialdir="/",title='Please select a directory')
        if len(dirname ) > 0:
                print "Directory Selected: %s" % dirname
                #tkMessageBox.showinfo("Selected Directory", dirname)
        os.chdir(dirname)
        """
        for file in glob.glob("*.torrent"):
                print file
                """
        new_dir = "output"
        if not os.path.isdir(dirname + "/" +new_dir):
                os.mkdir(dirname + "/" +new_dir)
        for files in glob.glob("*.torrent"):
                temp = open(files, 'rb')
                filename = str(temp.name)
                data = temp.read()
                metainfo = bencode.bdecode(data)
                info = metainfo['info']
                temp.close()
                tracker = metainfo['announce-list']
                #print metainfo['announce']
                print filename
                print "Amount of trackers: " +str(len(tracker))
                for i in range(len(tracker)):
                        if filter(lambda x: 'udp' in x,tracker[i]):
                                print filter(lambda x: 'udp' in x,tracker[i])
                                udp += 1
                                tracker[i].pop()
                        else:
                                track.append(tracker[i])

                print "Amount of trackers after: " +str(len(track))
                #print track
                '''
                new_metainfo = bencode.bdecode(data)
                new_metainfo['announce-list'] = track
                print new_metainfo['announce-list']'''
                metainfo['announce'] = track[0]
                #print metainfo['announce']
                metainfo['announce-list'] = track
                #print metainfo['announce-list']
                output = open(dirname + "/" +new_dir+"/"+filename, 'wb')
                output.write(bencode.bencode(metainfo))
                output.close()
                track = []
        tkMessageBox.showinfo("Torrent Renamer", "Batch Complete!\nUDP trackers removed: " +str(udp))

def selectFile():
        file = tkFileDialog.askopenfile(parent=app,mode='rb',title='Choose a file')
        if file != None:
            data = file.read()
            metainfo = bencode.bdecode(data)
            info = metainfo['info']
            tracker = metainfo['announce-list']
            file.close()
            print "File size: %d bytes. " % len(data)
            print tracker
            print hashlib.sha1(bencode.bencode(info)).hexdigest()
            #os.rename(file.name, hashlib.sha1(bencode.bencode(info)).hexdigest() +".torrent")
            tkMessageBox.showinfo("Torrent Info", "Torrent Name: " +str(file.name)+ "\nTorrent Size: " +str(len(data))+ "\nTorrent SHA hash: " +str(hashlib.sha1(bencode.bencode(info)).hexdigest()) +"\nTorrent Trackers: \n" +str(tracker))

app = Tkinter.Tk()
app.title("Torrent Renamer")
app.minsize(width=200, height=50)
app.iconbitmap(bitmap="icon.ico")
b = Tkinter.Button(app, text="Hash Renamer: Select Directory", command=selectDir)
c = Tkinter.Button(app, text="Remove UDP: Select Directory", command=selectUDP)
d = Tkinter.Button(app, text="Show Info: Select File", command=selectFile)

b.pack()
c.pack()
d.pack()
app.mainloop()


"""
def main():
	# Open torrent file
	torrent_file = open(sys.argv[1], "rb")
	metainfo = bencode.bdecode(torrent_file.read())
	info = metainfo['info']
	print hashlib.sha1(bencode.bencode(info)).hexdigest()

if __name__ == '__main__':
    main()
"""
