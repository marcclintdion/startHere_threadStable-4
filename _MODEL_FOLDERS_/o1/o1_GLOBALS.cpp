void  load_o1_FromHDtoSystemRAM(void*);                                     
void  delete_o1_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o1;                                                
FIBITMAP            *dib_o1;                                                
FIBITMAP           *temp_o1;                                                
BYTE             *pixels_o1;                                                  
//-------------------------------------------------------------
bool   o1_isLoadedFromDriveAndWaiting             = false;                  
bool   o1_isLoaded                                = false;                  
char  *o1_FilePath;                                                         
bool   o1_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o1_POSITION[]             = { -121.658714f, 33.214130f, 21.953690f, 1.0 }; 
GLfloat o1_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o1_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o1_VBO; 
GLuint o1_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o1_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o1_boundingBox[6]; 

//===================================================================================================================
void load_o1_VBOs(void)  
{ 
      #include    "o1.cpp" 
      glGenBuffers(1,              &o1_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o1_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o1), o1, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o1_INDICES.cpp"   
      glGenBuffers(1,              &o1_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o1_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o1_INDICES), o1_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
