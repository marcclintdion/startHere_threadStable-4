void  load_o20_FromHDtoSystemRAM(void*);                                     
void  delete_o20_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o20;                                                
FIBITMAP            *dib_o20;                                                
FIBITMAP           *temp_o20;                                                
BYTE             *pixels_o20;                                                  
//-------------------------------------------------------------
bool   o20_isLoadedFromDriveAndWaiting             = false;                  
bool   o20_isLoaded                                = false;                  
char  *o20_FilePath;                                                         
bool   o20_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o20_POSITION[]             = { 81.576508f, -34.491062f, 1.856569f, 1.0 }; 
GLfloat o20_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o20_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o20_VBO; 
GLuint o20_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o20_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o20_boundingBox[6]; 

//===================================================================================================================
void load_o20_VBOs(void)  
{ 
      #include    "o20.cpp" 
      glGenBuffers(1,              &o20_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o20_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o20), o20, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o20_INDICES.cpp"   
      glGenBuffers(1,              &o20_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o20_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o20_INDICES), o20_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
