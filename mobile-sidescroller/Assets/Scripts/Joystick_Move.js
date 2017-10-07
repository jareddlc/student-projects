
var buttonLeft: GUIText;
var buttonRight: GUIText;
var touch: Touch;
var playerObject: Transform;
var character : CharacterController;
var arrowLeft: GUITexture;
var arrowRight: GUITexture;
var movementSpeed: float = 4;

private var velocity : Vector3;	

function Start()
{

}

function Update()
{
	var movement = Vector3.zero;
	var tapCount = Input.touchCount;
	
	for (var i=0 ; i<tapCount ; i++) 
	{
		var touch = Input.GetTouch(i);
		var keyLeft = arrowLeft.HitTest(touch.position);
		var keyRight = arrowRight.HitTest(touch.position);
		
		if(touch.phase == TouchPhase.Stationary) 
		{  
			if(keyLeft)
			{
				buttonLeft.gameObject.active = true;
				movement = Vector3.right * -(movementSpeed);
			}
			if(keyRight)
			{
				buttonRight.gameObject.active = true;
				movement = Vector3.right * (movementSpeed);
			}
		}
	
		if(touch.phase == TouchPhase.Ended)
		{
			if(keyLeft)
			{
				buttonLeft.gameObject.active = false;
			}
			if(keyRight)
			{
				buttonRight.gameObject.active = false;
			}
		}
		
		//movement += Physics.gravity;
		movement *= Time.deltaTime;
		character.Move(movement);
		
		
	}
}
