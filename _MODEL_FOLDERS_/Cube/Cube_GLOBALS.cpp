void  load_Cube_FromHDtoSystemRAM(void*);                                     
void  delete_Cube_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_Cube;                                                
FIBITMAP            *dib_Cube;                                                
FIBITMAP           *temp_Cube;                                                
BYTE             *pixels_Cube;                                                  
//-------------------------------------------------------------
bool   Cube_isLoadedFromDriveAndWaiting             = false;                  
bool   Cube_isLoaded                                = false;                  
char  *Cube_FilePath;                                                         
bool   Cube_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat Cube_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat Cube_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat Cube_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint Cube_VBO; 
GLuint Cube_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint Cube_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat Cube_boundingBox[6]; 

//===================================================================================================================
void load_Cube_VBOs(void)  
{ 
      #include    "Cube.cpp" 
      glGenBuffers(1,              &Cube_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, Cube_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(Cube), Cube, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "Cube_INDICES.cpp"   
      glGenBuffers(1,              &Cube_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Cube_INDICES), Cube_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
