var logo: GUITexture;
private var gui : GUITexture;

function Start()
{
	gui = GetComponent(GUITexture);
	logo.gameObject.active = false;
}

function Update () 
{
	logo.gameObject.active = true;
}