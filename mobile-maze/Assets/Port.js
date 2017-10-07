var spawnpoint1 : Transform;
var spawnpoint2 : Transform;
var spawnpoint3 : Transform;
var spawnpoint4 : Transform;

function OnTriggerExit(other : Collider) {
	var Seed : int = Random.Range(1,4);
	
    if (other.tag == "Player") {
		if (Seed == 1)
			other.transform.position = spawnpoint1.position;
			
		if (Seed == 2)
			other.transform.position = spawnpoint2.position;
		
		if (Seed == 3)
			other.transform.position = spawnpoint3.position;
		
		if (Seed == 4)
			other.transform.position = spawnpoint4.position;
    }
}