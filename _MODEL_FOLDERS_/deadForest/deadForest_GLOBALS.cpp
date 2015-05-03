void  load_deadForest_FromHDtoSystemRAM(void*); 
void  delete_deadForest_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_deadForest; 
FIBITMAP            *dib_deadForest; 
FIBITMAP           *temp_deadForest; 
BYTE             *pixels_deadForest;   
//-------------------------------------------------------------
bool   deadForest_isLoadedFromDriveAndWaiting             = false; 
bool   deadForest_isLoaded                                = false; 
char  *deadForest_FilePath;                                        
bool   deadForest_isActive                                = false;   
//===================================================================================================================
GLfloat deadForest_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat deadForest_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat deadForest_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint deadForest_VBO; 
GLuint deadForest_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint deadForest_NORMALMAP; 

GLuint deadForest_COLORMAP; 
GLuint deadForest_MASK0MAP; 

//----------------------------------------------------------------- 
GLfloat deadForest_boundingBox[6]; 

//===================================================================================================================
void load_deadForest_VBOs(void)  
{ 
      #include    "deadForest.cpp" 
      glGenBuffers(1,              &deadForest_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, deadForest_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(deadForest), deadForest, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "deadForest_INDICES.cpp"   
      glGenBuffers(1,              &deadForest_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, deadForest_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(deadForest_INDICES), deadForest_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
