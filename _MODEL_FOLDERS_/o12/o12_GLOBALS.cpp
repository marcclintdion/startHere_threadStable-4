void  load_o12_FromHDtoSystemRAM(void*);                                     
void  delete_o12_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o12;                                                
FIBITMAP            *dib_o12;                                                
FIBITMAP           *temp_o12;                                                
BYTE             *pixels_o12;                                                  
//-------------------------------------------------------------
bool   o12_isLoadedFromDriveAndWaiting             = false;                  
bool   o12_isLoaded                                = false;                  
char  *o12_FilePath;                                                         
bool   o12_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o12_POSITION[]             = { 39.971016f, 0.402655f, 2.858086f, 1.0 }; 
GLfloat o12_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o12_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o12_VBO; 
GLuint o12_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o12_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o12_boundingBox[6]; 

//===================================================================================================================
void load_o12_VBOs(void)  
{ 
      #include    "o12.cpp" 
      glGenBuffers(1,              &o12_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o12_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o12), o12, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o12_INDICES.cpp"   
      glGenBuffers(1,              &o12_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o12_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o12_INDICES), o12_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
