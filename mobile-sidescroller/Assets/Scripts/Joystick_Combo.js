
//GUITex
var buttonLeft: GUIText;
var buttonRight: GUIText;
var buttonShoot: GUIText;
var buttonJump: GUIText;

//GUITexture
var arrowLeft: GUITexture;
var arrowRight: GUITexture;
var actionShoot: GUITexture;
var actionJump: GUITexture;

//Character
var character : CharacterController;

//Touch
var touch: Touch;

//Movement
var jumpSpeed : float = 16;
var inAirMultiplier : float = 0.25;	
var movementSpeed: float = 4;
private var canJump = true;
private var velocity : Vector3;	

function Update () 
{
	//Movement
	var movement = Vector3.zero;
	
	//Input Count
	var tapCount = Input.touchCount;
	
	for (var i=0 ; i<tapCount ; i++) 
	{
		var touch = Input.GetTouch(i);
		
		//GUITexture "HIT BOX"
		var keyLeft = arrowLeft.HitTest(touch.position);
		var keyRight = arrowRight.HitTest(touch.position);
		var keyShoot = actionShoot.HitTest(touch.position);
		var keyJump = actionJump.HitTest(touch.position);
		
		
		//If a stationary touch is made at each GUITexture
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
			if(keyShoot)
			{
				buttonShoot.gameObject.active = true;
			}
			if(keyJump)
			{
				movement += Vector3.up * jumpSpeed;
				buttonJump.gameObject.active = true;
			}
		}
		
		//If touch was released at each GUITexture
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
			if(keyShoot)
			{
				buttonShoot.gameObject.active = false;
			}
			if(keyJump)
			{
				buttonJump.gameObject.active = false;
			}
		}
	}
	movement += Physics.gravity;
	movement *= Time.deltaTime;
	character.Move(movement);
}