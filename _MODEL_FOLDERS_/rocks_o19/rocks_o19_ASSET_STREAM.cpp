#ifdef WIN32 
void load_rocks_o19_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_rocks_o19 = FreeImage_GetFileType(rocks_o19_FilePath, 0);                       
    dib_rocks_o19   = FreeImage_Load(fifmt_rocks_o19, rocks_o19_FilePath, 0);                    
    temp_rocks_o19  = dib_rocks_o19;                                                      
    dib_rocks_o19   = FreeImage_ConvertTo32Bits(temp_rocks_o19);                          
    FreeImage_Unload(temp_rocks_o19);                                            

    if( dib_rocks_o19 != NULL )                                                    
    {                                                                       
        pixels_rocks_o19 = (BYTE*)FreeImage_GetBits(dib_rocks_o19);                       
    }                                                                     

    rocks_o19_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_rocks_o19_FromSystemRAM(void)                                          
{                                                                           
    if( dib_rocks_o19 != NULL )                                                    
    {                                                                       
        free(pixels_rocks_o19);                                                    
        FreeImage_Unload(dib_rocks_o19);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
