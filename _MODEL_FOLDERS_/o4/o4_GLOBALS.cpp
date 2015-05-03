void  load_o4_FromHDtoSystemRAM(void*);                                     
void  delete_o4_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o4;                                                
FIBITMAP            *dib_o4;                                                
FIBITMAP           *temp_o4;                                                
BYTE             *pixels_o4;                                                  
//-------------------------------------------------------------
bool   o4_isLoadedFromDriveAndWaiting             = false;                  
bool   o4_isLoaded                                = false;                  
char  *o4_FilePath;                                                         
bool   o4_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o4_POSITION[]             = { -0.871714f, 33.197796f, 11.981781f, 1.0 }; 
GLfloat o4_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o4_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o4_VBO; 
GLuint o4_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o4_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o4_boundingBox[6]; 

//===================================================================================================================
void load_o4_VBOs(void)  
{ 
      #include    "o4.cpp" 
      glGenBuffers(1,              &o4_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o4_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o4), o4, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o4_INDICES.cpp"   
      glGenBuffers(1,              &o4_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o4_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o4_INDICES), o4_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
