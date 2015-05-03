void  load_o13_FromHDtoSystemRAM(void*);                                     
void  delete_o13_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o13;                                                
FIBITMAP            *dib_o13;                                                
FIBITMAP           *temp_o13;                                                
BYTE             *pixels_o13;                                                  
//-------------------------------------------------------------
bool   o13_isLoadedFromDriveAndWaiting             = false;                  
bool   o13_isLoaded                                = false;                  
char  *o13_FilePath;                                                         
bool   o13_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o13_POSITION[]             = { 80.104584f, 1.314474f, 4.637854f, 1.0 }; 
GLfloat o13_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o13_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o13_VBO; 
GLuint o13_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o13_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o13_boundingBox[6]; 

//===================================================================================================================
void load_o13_VBOs(void)  
{ 
      #include    "o13.cpp" 
      glGenBuffers(1,              &o13_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o13_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o13), o13, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o13_INDICES.cpp"   
      glGenBuffers(1,              &o13_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o13_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o13_INDICES), o13_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
