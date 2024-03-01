#!/bin/bash

# Definim calea către executabilele serverului și clientului
Path=$(pwd)
SERVER_EXECUTABLE=$Path"/Server"
CLIENT_EXECUTABLE=$Path"/Client"

# Pornim serverul și clientul în fundal
$SERVER_EXECUTABLE &
$CLIENT_EXECUTABLE &

# Afisam un mesaj de confirmare
echo "Server and client started."