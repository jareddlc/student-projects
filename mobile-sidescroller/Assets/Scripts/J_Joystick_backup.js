@script RequireComponent(GUITexture)

var button_pressed: GUIText;
var touch: Touch;
var main_object: Transform;
var arrowLeft: GUITexture;
var arrowRight: GUITexture;
private var gui : GUITexture;

function Start()
{
	gui = GetComponent(GUITexture);
}

function Update()
{
	var tapCount = Input.touchCount;
	for (var i=0 ; i<tapCount ; i++) 
	{
		var touch = Input.GetTouch(i);
		//Do whatever you want with the current touch.
		//var evt : Touch = Input.GetTouch(i); 
		var keyLeft = arrowLeft.HitTest(touch.position);
		var keyRight = arrowRight.HitTest(touch.position);
		
		var buttonPressed = GetComponent.<GUITexture>().HitTest(touch.position);
		
		if(touch.phase == TouchPhase.Began) 
		{  
			if(buttonPressed)
			{
			   button_pressed.gameObject.active = true;
			}
		}
		
		if(touch.phase == TouchPhase.Ended)
		{
			if(buttonPressed)
			{
				button_pressed.gameObject.active = false;
			}
		}
	}
}
