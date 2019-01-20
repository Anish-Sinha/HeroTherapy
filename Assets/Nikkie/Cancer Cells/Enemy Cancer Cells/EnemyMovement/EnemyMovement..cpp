// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include "pch.h"
#include <iostream>

using UnityEngine;
using System.Collections;

public class EnemyMovement : MonoBehavior {

	Transform player;				//Player's position.
	PlayerHealth playerHealth;		//Player's health.
	EnemyHealth enemyHealth;		//Enemy's health.
	NavMesAgent nav;				//Nav mesh agent.

	void awake() {
		player = GameObject.FindGameObjectWithTag("Player").transform;
		playerHealth = player.GetComponent <PlayerHealth> ();
		enemyHealth = GetComponent <EnemyHealth> ();
		nav = GetComponent <NavMeshAgent>();
	}

	void update() {
		if (enemyHealth.currentHealth > 0 && playerHealth.currentHealth > 0) { // If the enemy and the player have health left...
			nav.SetDestination(player.position);							  // ... set the destination of the nav mesh agent to the player.
		}
		else {
			nav.enabled = false;
		}
	}
}