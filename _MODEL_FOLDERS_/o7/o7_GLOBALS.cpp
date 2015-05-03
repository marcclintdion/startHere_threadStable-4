void  load_o7_FromHDtoSystemRAM(void*);                                     
void  delete_o7_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o7;                                                
FIBITMAP            *dib_o7;                                                
FIBITMAP           *temp_o7;                                                
BYTE             *pixels_o7;                                                  
//-------------------------------------------------------------
bool   o7_isLoadedFromDriveAndWaiting             = false;                  
bool   o7_isLoaded                                = false;                  
char  *o7_FilePath;                                                         
bool   o7_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o7_POSITION[]             = { 119.390434f, 33.676746f, 7.198694f, 1.0 }; 
GLfloat o7_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o7_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o7_VBO; 
GLuint o7_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o7_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o7_boundingBox[6]; 

//===================================================================================================================
void load_o7_VBOs(void)  
{ 
      #include    "o7.cpp" 
      glGenBuffers(1,              &o7_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o7_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o7), o7, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o7_INDICES.cpp"   
      glGenBuffers(1,              &o7_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o7_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o7_INDICES), o7_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
