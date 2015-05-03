void  load_rocks_o18_FromHDtoSystemRAM(void*);                                     
void  delete_rocks_o18_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_rocks_o18;                                                
FIBITMAP            *dib_rocks_o18;                                                
FIBITMAP           *temp_rocks_o18;                                                
BYTE             *pixels_rocks_o18;                                                  
//-------------------------------------------------------------
bool   rocks_o18_isLoadedFromDriveAndWaiting             = false;                  
bool   rocks_o18_isLoaded                                = false;                  
char  *rocks_o18_FilePath;                                                         
bool   rocks_o18_isActive                                = true;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat rocks_o18_POSITION[]             = { -13.021724f, -38.885677f, 5.576614f, 1.0 }; 
GLfloat rocks_o18_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat rocks_o18_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint rocks_o18_VBO; 
GLuint rocks_o18_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint rocks_o18_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat rocks_o18_boundingBox[6]; 

//===================================================================================================================
void load_rocks_o18_VBOs(void)  
{ 
      #include    "rocks_o18.cpp" 
      glGenBuffers(1,              &rocks_o18_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, rocks_o18_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(rocks_o18), rocks_o18, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "rocks_o18_INDICES.cpp"   
      glGenBuffers(1,              &rocks_o18_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o18_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rocks_o18_INDICES), rocks_o18_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
