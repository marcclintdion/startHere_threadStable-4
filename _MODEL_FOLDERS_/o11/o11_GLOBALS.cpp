void  load_o11_FromHDtoSystemRAM(void*);                                     
void  delete_o11_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o11;                                                
FIBITMAP            *dib_o11;                                                
FIBITMAP           *temp_o11;                                                
BYTE             *pixels_o11;                                                  
//-------------------------------------------------------------
bool   o11_isLoadedFromDriveAndWaiting             = false;                  
bool   o11_isLoaded                                = false;                  
char  *o11_FilePath;                                                         
bool   o11_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o11_POSITION[]             = { -0.580673f, 1.646565f, 1.759505f, 1.0 }; 
GLfloat o11_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o11_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o11_VBO; 
GLuint o11_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o11_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o11_boundingBox[6]; 

//===================================================================================================================
void load_o11_VBOs(void)  
{ 
      #include    "o11.cpp" 
      glGenBuffers(1,              &o11_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o11_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o11), o11, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o11_INDICES.cpp"   
      glGenBuffers(1,              &o11_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o11_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o11_INDICES), o11_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
