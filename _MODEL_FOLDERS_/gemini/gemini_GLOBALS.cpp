void  load_gemini_FromHDtoSystemRAM(void*);                                     
void  delete_gemini_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_gemini;                                                
FIBITMAP            *dib_gemini;                                                
FIBITMAP           *temp_gemini;                                                
BYTE             *pixels_gemini;                                                  
//-------------------------------------------------------------
bool   gemini_isLoadedFromDriveAndWaiting             = false;                  
bool   gemini_isLoaded                                = false;                  
char  *gemini_FilePath;                                                         
bool   gemini_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat gemini_POSITION[]             = { 0.000000f, 0.000000f, 0.320007f, 1.0 }; 
GLfloat gemini_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat gemini_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint gemini_VBO; 
GLuint gemini_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint gemini_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat gemini_boundingBox[6]; 

//===================================================================================================================
void load_gemini_VBOs(void)  
{ 
      #include    "gemini.cpp" 
      glGenBuffers(1,              &gemini_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, gemini_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(gemini), gemini, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "gemini_INDICES.cpp"   
      glGenBuffers(1,              &gemini_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gemini_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(gemini_INDICES), gemini_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
