void  load_rocks_o19_FromHDtoSystemRAM(void*);                                     
void  delete_rocks_o19_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_rocks_o19;                                                
FIBITMAP            *dib_rocks_o19;                                                
FIBITMAP           *temp_rocks_o19;                                                
BYTE             *pixels_rocks_o19;                                                  
//-------------------------------------------------------------
bool   rocks_o19_isLoadedFromDriveAndWaiting             = false;                  
bool   rocks_o19_isLoaded                                = false;                  
char  *rocks_o19_FilePath;                                                         
bool   rocks_o19_isActive                                = true;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat rocks_o19_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat rocks_o19_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat rocks_o19_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint rocks_o19_VBO; 
GLuint rocks_o19_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint rocks_o19_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat rocks_o19_boundingBox[6]; 

//===================================================================================================================
void load_rocks_o19_VBOs(void)  
{ 
      #include    "rocks_o19.cpp" 
      glGenBuffers(1,              &rocks_o19_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, rocks_o19_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(rocks_o19), rocks_o19, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "rocks_o19_INDICES.cpp"   
      glGenBuffers(1,              &rocks_o19_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o19_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rocks_o19_INDICES), rocks_o19_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
