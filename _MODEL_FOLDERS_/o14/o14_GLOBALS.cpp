void  load_o14_FromHDtoSystemRAM(void*);                                     
void  delete_o14_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o14;                                                
FIBITMAP            *dib_o14;                                                
FIBITMAP           *temp_o14;                                                
BYTE             *pixels_o14;                                                  
//-------------------------------------------------------------
bool   o14_isLoadedFromDriveAndWaiting             = false;                  
bool   o14_isLoaded                                = false;                  
char  *o14_FilePath;                                                         
bool   o14_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o14_POSITION[]             = { 120.639740f, -0.285499f, 2.437956f, 1.0 }; 
GLfloat o14_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o14_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o14_VBO; 
GLuint o14_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o14_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o14_boundingBox[6]; 

//===================================================================================================================
void load_o14_VBOs(void)  
{ 
      #include    "o14.cpp" 
      glGenBuffers(1,              &o14_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o14_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o14), o14, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o14_INDICES.cpp"   
      glGenBuffers(1,              &o14_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o14_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o14_INDICES), o14_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
