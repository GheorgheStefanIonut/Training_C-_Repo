#!/bin/bash

# Definim calea către executabilele serverului și clientului
Path=$(pwd)
SERVER_EXECUTABLE=$Path"/Server"
CLIENT_EXECUTABLE=$Path"/Client"

# Compilare 
if [ ! -f "$SERVER_EXECUTABLE" ]; then
    g++ Server.cpp -o $SERVER_EXECUTABLE -lrt
fi

if [ ! -f "$CLIENT_EXECUTABLE" ]; then
    g++ Client.cpp -o $CLIENT_EXECUTABLE -lrt
fi

# Pornim serverul și clientul în fundal
$SERVER_EXECUTABLE &
$CLIENT_EXECUTABLE &

# Afisam un mesaj de confirmare
echo "Server and client started."

#chmod +x bash_script.sh   			#acorda permisiuni de executie
#dos2unix ./bash_script.sh			#convertire la format pt Linux
#./bash_script.sh					#rulare script