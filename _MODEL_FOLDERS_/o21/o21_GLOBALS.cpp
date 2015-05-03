void  load_o21_FromHDtoSystemRAM(void*);                                     
void  delete_o21_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o21;                                                
FIBITMAP            *dib_o21;                                                
FIBITMAP           *temp_o21;                                                
BYTE             *pixels_o21;                                                  
//-------------------------------------------------------------
bool   o21_isLoadedFromDriveAndWaiting             = false;                  
bool   o21_isLoaded                                = false;                  
char  *o21_FilePath;                                                         
bool   o21_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o21_POSITION[]             = { 120.440926f, -33.020462f, 2.041833f, 1.0 }; 
GLfloat o21_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o21_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o21_VBO; 
GLuint o21_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o21_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o21_boundingBox[6]; 

//===================================================================================================================
void load_o21_VBOs(void)  
{ 
      #include    "o21.cpp" 
      glGenBuffers(1,              &o21_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o21_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o21), o21, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o21_INDICES.cpp"   
      glGenBuffers(1,              &o21_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o21_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o21_INDICES), o21_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
