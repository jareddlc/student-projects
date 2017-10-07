var object : GameObject;

var found1 : GameObject;
var found2 : GameObject;
var found3 : GameObject;
var found4 : GameObject;

	found1.active = false;
	found2.active = false;
	found3.active = false;
	found4.active = false;

var spawnpoint1 : Transform;
var spawnpoint2 : Transform;
var spawnpoint3 : Transform;
var spawnpoint4 : Transform;

function Start() {
	var Seed : int = Random.Range(1,5);
	
		if (Seed == 1){
			Instantiate(object, spawnpoint1.position, spawnpoint1.rotation);
			found1.active = true;
			}
			
		if (Seed == 2){
			Instantiate(object, spawnpoint2.position, spawnpoint2.rotation);
			found2.active = true;
			}
		
		if (Seed == 3){
			Instantiate(object, spawnpoint3.position, spawnpoint3.rotation);
			found3.active = true;
			}
		
		if (Seed == 4){
			Instantiate(object, spawnpoint4.position, spawnpoint4.rotation);
			found4.active = true;
			}
}