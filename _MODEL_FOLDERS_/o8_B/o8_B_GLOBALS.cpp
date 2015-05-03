void  load_o8_B_FromHDtoSystemRAM(void*);                                     
void  delete_o8_B_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o8_B;                                                
FIBITMAP            *dib_o8_B;                                                
FIBITMAP           *temp_o8_B;                                                
BYTE             *pixels_o8_B;                                                  
//-------------------------------------------------------------
bool   o8_B_isLoadedFromDriveAndWaiting             = false;                  
bool   o8_B_isLoaded                                = false;                  
char  *o8_B_FilePath;                                                         
bool   o8_B_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o8_B_POSITION[]             = { -122.925102f, -3.375342f, 8.094350f, 1.0 }; 
GLfloat o8_B_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o8_B_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o8_B_VBO; 
GLuint o8_B_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o8_B_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o8_B_boundingBox[6]; 

//===================================================================================================================
void load_o8_B_VBOs(void)  
{ 
      #include    "o8_B.cpp" 
      glGenBuffers(1,              &o8_B_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o8_B_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o8_B), o8_B, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o8_B_INDICES.cpp"   
      glGenBuffers(1,              &o8_B_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o8_B_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o8_B_INDICES), o8_B_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
