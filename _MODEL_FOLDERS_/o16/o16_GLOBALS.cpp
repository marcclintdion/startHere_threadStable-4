void  load_o16_FromHDtoSystemRAM(void*);                                     
void  delete_o16_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o16;                                                
FIBITMAP            *dib_o16;                                                
FIBITMAP           *temp_o16;                                                
BYTE             *pixels_o16;                                                  
//-------------------------------------------------------------
bool   o16_isLoadedFromDriveAndWaiting             = false;                  
bool   o16_isLoaded                                = false;                  
char  *o16_FilePath;                                                         
bool   o16_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o16_POSITION[]             = { -78.813881f, -34.553402f, 2.456429f, 1.0 }; 
GLfloat o16_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o16_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o16_VBO; 
GLuint o16_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o16_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o16_boundingBox[6]; 

//===================================================================================================================
void load_o16_VBOs(void)  
{ 
      #include    "o16.cpp" 
      glGenBuffers(1,              &o16_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o16_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o16), o16, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o16_INDICES.cpp"   
      glGenBuffers(1,              &o16_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o16_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o16_INDICES), o16_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
