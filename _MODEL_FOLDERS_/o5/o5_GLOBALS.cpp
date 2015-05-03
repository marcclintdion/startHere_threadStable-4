void  load_o5_FromHDtoSystemRAM(void*);                                     
void  delete_o5_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o5;                                                
FIBITMAP            *dib_o5;                                                
FIBITMAP           *temp_o5;                                                
BYTE             *pixels_o5;                                                  
//-------------------------------------------------------------
bool   o5_isLoadedFromDriveAndWaiting             = false;                  
bool   o5_isLoaded                                = false;                  
char  *o5_FilePath;                                                         
bool   o5_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o5_POSITION[]             = { 40.806286f, 33.177685f, 11.825097f, 1.0 }; 
GLfloat o5_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o5_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o5_VBO; 
GLuint o5_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o5_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o5_boundingBox[6]; 

//===================================================================================================================
void load_o5_VBOs(void)  
{ 
      #include    "o5.cpp" 
      glGenBuffers(1,              &o5_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o5_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o5), o5, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o5_INDICES.cpp"   
      glGenBuffers(1,              &o5_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o5_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o5_INDICES), o5_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
