void  load_o15_FromHDtoSystemRAM(void*);                                     
void  delete_o15_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o15;                                                
FIBITMAP            *dib_o15;                                                
FIBITMAP           *temp_o15;                                                
BYTE             *pixels_o15;                                                  
//-------------------------------------------------------------
bool   o15_isLoadedFromDriveAndWaiting             = false;                  
bool   o15_isLoaded                                = false;                  
char  *o15_FilePath;                                                         
bool   o15_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o15_POSITION[]             = { -121.720802f, -37.064995f, 3.061348f, 1.0 }; 
GLfloat o15_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o15_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o15_VBO; 
GLuint o15_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o15_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o15_boundingBox[6]; 

//===================================================================================================================
void load_o15_VBOs(void)  
{ 
      #include    "o15.cpp" 
      glGenBuffers(1,              &o15_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o15_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o15), o15, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o15_INDICES.cpp"   
      glGenBuffers(1,              &o15_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o15_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o15_INDICES), o15_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
