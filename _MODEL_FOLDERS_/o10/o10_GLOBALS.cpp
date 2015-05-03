void  load_o10_FromHDtoSystemRAM(void*);                                     
void  delete_o10_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o10;                                                
FIBITMAP            *dib_o10;                                                
FIBITMAP           *temp_o10;                                                
BYTE             *pixels_o10;                                                  
//-------------------------------------------------------------
bool   o10_isLoadedFromDriveAndWaiting             = false;                  
bool   o10_isLoaded                                = false;                  
char  *o10_FilePath;                                                         
bool   o10_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o10_POSITION[]             = { -41.040379f, 1.176962f, 3.594046f, 1.0 }; 
GLfloat o10_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o10_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o10_VBO; 
GLuint o10_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o10_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o10_boundingBox[6]; 

//===================================================================================================================
void load_o10_VBOs(void)  
{ 
      #include    "o10.cpp" 
      glGenBuffers(1,              &o10_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o10_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o10), o10, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o10_INDICES.cpp"   
      glGenBuffers(1,              &o10_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o10_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o10_INDICES), o10_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
