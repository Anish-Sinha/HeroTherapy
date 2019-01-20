using UnityEngine;
using System.Collections;

public class EnemySpawn : MonoBehavior {

    public PlayerHealth playerHealth;   //Player's health.
    public GameObject enemy;            //Enemy prefab to be spawned.
    public float spawnTime = 3f;        //Spawn delay wait time.
    public Transform[] spawnPoints;     //Stores the coordinates of enemy spawn points.
    
    void start(){
        InvokeRepeating("Spawn", spawnTime; spawnTime);
    }

    void spawn() {
        if (playerHealth.currentHealth <= 0f) {  //if player has no more health
            return;
        }

        int spawnPointIndex = Random.Range(0, spawnPoints.length);  //Generate random number between 0 and total number of spawn points

        Instantiate(enemy, spawnPoints[spawnPointIndex].position, spawnPoints[spawnPointIndex].rotation);
    }
 }