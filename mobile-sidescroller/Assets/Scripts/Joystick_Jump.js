@script RequireComponent(CharacterController)

var buttonShoot: GUIText;
var buttonJump: GUIText;
var touch: Touch;
var playerObject: Transform;
var character : CharacterController;
var actionShoot: GUITexture;
var actionJump: GUITexture;

var jumpSpeed : float = 160;
var inAirMultiplier : float = 0.25;	
var movementSpeed: float = 4;

private var canJump = true;
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
		var keyShoot = actionShoot.HitTest(touch.position);
		var keyJump = actionJump.HitTest(touch.position);
		
		if(touch.phase == TouchPhase.Stationary) 
		{  
			if(keyShoot)
			{
				buttonShoot.gameObject.active = true;
			}
			if(keyJump)
			{
				movement = Vector3.up * jumpSpeed;
				buttonJump.gameObject.active = true;
			}
		}
	
		if(touch.phase == TouchPhase.Ended)
		{
			if(keyShoot)
			{
				buttonShoot.gameObject.active = false;
			}
			if(keyJump)
			{
				buttonJump.gameObject.active = false;
			}
		}
		//movement += Physics.gravity;
		//movement *= Time.deltaTime;
		
		character.Move(movement);		
	}	
}