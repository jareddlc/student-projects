var Text1:GameObject;
var Text2:GameObject;

function Start(){
	Text1.active = true;
	Text2.active = true;
}

function OnTriggerEnter(something:Collider) {
	if (something.name == "Player")
		Text1.active = true;
		Text2.active = true;
}

function OnTriggerExit(something:Collider){
	if (something.name == "Player")
		Text1.active = false;
		Text2.active = false;
}

function Update () {
}