#include <painlessMesh.h>
#include "main.h"

// Prep Global Variables
namespace globals {
    Scheduler user_scheduler; // to control your personal task
    painlessMesh mesh;
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
}

void newConnectionCallback(uint32_t nodeId) {
    Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void setup() {
  Serial.begin(115200);

//mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  globals::mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

  globals::mesh.init(MESH_PREFIX, MESH_PASSWORD, &globals::user_scheduler, MESH_PORT );
  globals::mesh.onReceive(&receivedCallback);
  globals::mesh.onNewConnection(&newConnectionCallback);
}

void loop() {
  // it will run the user scheduler as well
  globals::mesh.update();
}