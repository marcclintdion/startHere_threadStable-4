void  load_rocks_o21_FromHDtoSystemRAM(void*);                                     
void  delete_rocks_o21_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_rocks_o21;                                                
FIBITMAP            *dib_rocks_o21;                                                
FIBITMAP           *temp_rocks_o21;                                                
BYTE             *pixels_rocks_o21;                                                  
//-------------------------------------------------------------
bool   rocks_o21_isLoadedFromDriveAndWaiting             = false;                  
bool   rocks_o21_isLoaded                                = false;                  
char  *rocks_o21_FilePath;                                                         
bool   rocks_o21_isActive                                = true;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat rocks_o21_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat rocks_o21_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat rocks_o21_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint rocks_o21_VBO; 
GLuint rocks_o21_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint rocks_o21_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat rocks_o21_boundingBox[6]; 

//===================================================================================================================
void load_rocks_o21_VBOs(void)  
{ 
      #include    "rocks_o21.cpp" 
      glGenBuffers(1,              &rocks_o21_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, rocks_o21_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(rocks_o21), rocks_o21, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "rocks_o21_INDICES.cpp"   
      glGenBuffers(1,              &rocks_o21_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o21_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rocks_o21_INDICES), rocks_o21_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
