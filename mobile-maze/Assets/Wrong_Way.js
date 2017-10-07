var Text1:GameObject;
var Text2:GameObject;
var Text3:GameObject;

function Start(){
	Text1.active = false;
	Text2.active = false;
	Text3.active = false;
}

function OnTriggerEnter(something:Collider) {
	if (something.name == "Player")
		Text1.active = true;
		Text2.active = true;
		Text3.active = true;
}

function OnTriggerExit(something:Collider){
	if (something.name == "Player")
		Text1.active = false;
		Text2.active = false;
		Text3.active = false;
}

function Update () {
}