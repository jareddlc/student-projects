# torrent-cleaner
This application takes a directory of torrent files and prepare them for ingestion in a custom torrent tracking system. The system did not allow for duplicates torrent files or torrent files with UDP protocols.

### Dependencies

##### Python 2.7
Python is a programming language that lets you work quickly
and integrate systems more effectively.

##### bencode
This package simply re-packages the existing bencoding and bdecoding implemention from the ‘official’ BitTorrent client as a separate, leight-weight package for re-using them without having the entire BitTorrent software as a dependency.

```
$ python -m site # get python paths. Look for 'USER_SITE'
$ mkdir -p <USER_SITE> # replace 'USER_SITE' with the path from step above
$ cp -r BitTorrent-bencode-5.0.8.1 <USER_SITE>
$ cd <USER_SITE>/BitTorrent-bencode-5.0.8.1
$ sudo python setup.py install
```

### Running

```
$ python torrent-cleaner.py
```
