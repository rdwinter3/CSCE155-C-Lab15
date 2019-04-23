/**
 * Uses ODBC to establish a connection to a mySQL database
 * filled with various game information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

#include "games.h"
#include "odbc_utils.h"
#include "databaseInfo.h"

int main(int argc, char** argv) {
  int i;

  // Each stores various information about the connection
  SQLHANDLE sqlenvhandle;
  SQLHANDLE sqlconnectionhandle;
  SQLHANDLE sqlstatementhandle;

  // String to store info that will be used to connect
  char* connectionInfo;

  // Create the string containing information about the database connection
  asprintf(&connectionInfo,
           "DRIVER={%s};SERVER=%s;"
           "PORT=%s;DATABASE=%s;UID=%s;PWD=%s;",
           driver, server, port, database, userID, password);

  // Connect to the DB.  Exit if there's a problem.
  if (!setupConnection(&sqlenvhandle, &sqlconnectionhandle, &sqlstatementhandle,
                       connectionInfo)) {
    // Cleans up the connection before exiting
    finishConnection(sqlenvhandle, sqlstatementhandle, sqlconnectionhandle);
    return -1;
  }

  // at this point, we have our sql connection handle; we can use it in the
  // games API...

  // TODO: 1. Define string variables to hold your game's name, publisher,
  // platform
	char name[256] = "Counter Strike Source";
	char publisher[256] = "Valve";
	char platform[256] = "PC";
	int year = 2004;
  // TODO: 2. Check that your game does not already exist, quit if it does
	
	VideoGame* game = getGame(name, sqlstatementhandle);
	if(game!=NULL){
		exit(0);
	}
  // TODO: 3. Check that a record for your publisher doesn't already exist,
  //         if it does use it, otherwise add it
		
	Platform* platformz = getPlatform(platform, sqlstatementhandle);
  if(platformz==NULL){
		addPlatform(name, sqlstatementhandle);
	}
  // TODO: 4. Check that a record for your platform doesn't already exist,
  //         if it does use it, otherwise add it
	Publisher* publisherz = getPublisher(publisher, sqlstatementhandle);
	 if(platformz==NULL){
		addPublisher(name, sqlstatementhandle);
	}
  // TODO: 5. Add the video game to the database
	addVideoGame(name, publisherz->id, sqlstatementhandle);
  //addVideoGame("Pac Man's Revenge", 12345678, sqlstatementhandle);
  //extractError("", sqlstatementhandle, SQL_HANDLE_STMT);
  // TODO: 6. Load the game from the database
	game = getGame(name, sqlstatementhandle);
  // TODO: 7. Associate your game with the platform with a particular release
  // year
	addAvailability(game->id, platformz->id, year, sqlstatementhandle);
  // Cleans up connection before exiting
  finishConnection(sqlenvhandle, sqlstatementhandle, sqlconnectionhandle);
}
