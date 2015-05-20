void extractError(char *fn, SQLHANDLE handle, SQLSMALLINT type);
void finishConnection(SQLHANDLE envHandle, SQLHANDLE statementHandle, SQLHANDLE connectionHandle);
int openConnectionVerbose(SQLHANDLE handle, SQLCHAR* connectionInfo);
int setupConnection(SQLHANDLE* sqlenvhandle, SQLHANDLE* sqlconnectionhandle,
                    SQLHANDLE* sqlstatementhandle, SQLCHAR* connectionInfo);
void printGame(VideoGame* game);
