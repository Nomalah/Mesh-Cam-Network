#pragma once

#include <painlessMesh.h>

#define MESH_PREFIX   "Mesh-Cam-Network"
#define MESH_PASSWORD "Person-Counter"
#define MESH_PORT     42069

#define PRIMARY_NODE_ID  1234
#define THIS_NODE_ID  1234


namespace globals {
    extern Scheduler user_scheduler;
    extern painlessMesh mesh;
}