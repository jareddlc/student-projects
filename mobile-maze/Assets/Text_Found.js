var Text_found : GameObject;

function Start() {
	Text_found.active = false;
}

function OnTriggerEnter(something : Collider) {
	if (something.name == "Player")
		Text_found.active = true;
}

function OnTriggerExit() {
	Text_found.active = false;
}

function Update () {
}