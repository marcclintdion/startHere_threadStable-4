#ifdef WIN32 
void load_rocks_o18_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_rocks_o18 = FreeImage_GetFileType(rocks_o18_FilePath, 0);                       
    dib_rocks_o18   = FreeImage_Load(fifmt_rocks_o18, rocks_o18_FilePath, 0);                    
    temp_rocks_o18  = dib_rocks_o18;                                                      
    dib_rocks_o18   = FreeImage_ConvertTo32Bits(temp_rocks_o18);                          
    FreeImage_Unload(temp_rocks_o18);                                            

    if( dib_rocks_o18 != NULL )                                                    
    {                                                                       
        pixels_rocks_o18 = (BYTE*)FreeImage_GetBits(dib_rocks_o18);                       
    }                                                                     

    rocks_o18_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_rocks_o18_FromSystemRAM(void)                                          
{                                                                           
    if( dib_rocks_o18 != NULL )                                                    
    {                                                                       
        free(pixels_rocks_o18);                                                    
        FreeImage_Unload(dib_rocks_o18);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
