void  load_o19_FromHDtoSystemRAM(void*);                                     
void  delete_o19_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o19;                                                
FIBITMAP            *dib_o19;                                                
FIBITMAP           *temp_o19;                                                
BYTE             *pixels_o19;                                                  
//-------------------------------------------------------------
bool   o19_isLoadedFromDriveAndWaiting             = false;                  
bool   o19_isLoaded                                = false;                  
char  *o19_FilePath;                                                         
bool   o19_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o19_POSITION[]             = { 39.998295f, -36.065983f, 2.603972f, 1.0 }; 
GLfloat o19_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o19_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o19_VBO; 
GLuint o19_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o19_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o19_boundingBox[6]; 

//===================================================================================================================
void load_o19_VBOs(void)  
{ 
      #include    "o19.cpp" 
      glGenBuffers(1,              &o19_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o19_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o19), o19, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o19_INDICES.cpp"   
      glGenBuffers(1,              &o19_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o19_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o19_INDICES), o19_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
