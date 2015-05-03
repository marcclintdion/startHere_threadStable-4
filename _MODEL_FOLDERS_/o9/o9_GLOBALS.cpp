void  load_o9_FromHDtoSystemRAM(void*);                                     
void  delete_o9_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o9;                                                
FIBITMAP            *dib_o9;                                                
FIBITMAP           *temp_o9;                                                
BYTE             *pixels_o9;                                                  
//-------------------------------------------------------------
bool   o9_isLoadedFromDriveAndWaiting             = false;                  
bool   o9_isLoaded                                = false;                  
char  *o9_FilePath;                                                         
bool   o9_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o9_POSITION[]             = { -81.114830f, 1.892219f, 8.084844f, 1.0 }; 
GLfloat o9_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o9_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o9_VBO; 
GLuint o9_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o9_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o9_boundingBox[6]; 

//===================================================================================================================
void load_o9_VBOs(void)  
{ 
      #include    "o9.cpp" 
      glGenBuffers(1,              &o9_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o9_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o9), o9, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o9_INDICES.cpp"   
      glGenBuffers(1,              &o9_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o9_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o9_INDICES), o9_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
