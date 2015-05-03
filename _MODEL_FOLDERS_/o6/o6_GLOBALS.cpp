void  load_o6_FromHDtoSystemRAM(void*);                                     
void  delete_o6_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o6;                                                
FIBITMAP            *dib_o6;                                                
FIBITMAP           *temp_o6;                                                
BYTE             *pixels_o6;                                                  
//-------------------------------------------------------------
bool   o6_isLoadedFromDriveAndWaiting             = false;                  
bool   o6_isLoaded                                = false;                  
char  *o6_FilePath;                                                         
bool   o6_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o6_POSITION[]             = { 80.572105f, 33.819580f, 11.604010f, 1.0 }; 
GLfloat o6_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o6_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o6_VBO; 
GLuint o6_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o6_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o6_boundingBox[6]; 

//===================================================================================================================
void load_o6_VBOs(void)  
{ 
      #include    "o6.cpp" 
      glGenBuffers(1,              &o6_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o6_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o6), o6, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o6_INDICES.cpp"   
      glGenBuffers(1,              &o6_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o6_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o6_INDICES), o6_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
