typedef struct {
  int id;
  char name[1024];
} Publisher;

typedef struct {
  int id;
  char name[1024];
} Platform;

typedef struct {
  int id;
  int numPlatforms;
  char name[1024];
  int* years;
  Platform** platforms;
  Publisher* publisher;
} VideoGame;

SQLRETURN addVideoGame(char* name, int publisherID, SQLHANDLE handle);
SQLRETURN addPlatform(char* name, SQLHANDLE handle);
SQLRETURN addPublisher(char* name, SQLHANDLE handle);
SQLRETURN addAvailability(int gameID, int platformID, int publishYear,
                          SQLHANDLE handle);
VideoGame* getGame(char* name, SQLHANDLE handle);
Publisher* getPublisher(char* name, SQLHANDLE handle);
Platform* getPlatform(char* name, SQLHANDLE handle);
void getAvailability(VideoGame* game, SQLHANDLE handle);
VideoGame** getAllGames(int* numGames, SQLHANDLE handle);
