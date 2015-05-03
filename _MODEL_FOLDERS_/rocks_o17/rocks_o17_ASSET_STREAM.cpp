#ifdef WIN32 
void load_rocks_o17_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_rocks_o17 = FreeImage_GetFileType(rocks_o17_FilePath, 0);                       
    dib_rocks_o17   = FreeImage_Load(fifmt_rocks_o17, rocks_o17_FilePath, 0);                    
    temp_rocks_o17  = dib_rocks_o17;                                                      
    dib_rocks_o17   = FreeImage_ConvertTo32Bits(temp_rocks_o17);                          
    FreeImage_Unload(temp_rocks_o17);                                            

    if( dib_rocks_o17 != NULL )                                                    
    {                                                                       
        pixels_rocks_o17 = (BYTE*)FreeImage_GetBits(dib_rocks_o17);                       
    }                                                                     

    rocks_o17_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_rocks_o17_FromSystemRAM(void)                                          
{                                                                           
    if( dib_rocks_o17 != NULL )                                                    
    {                                                                       
        free(pixels_rocks_o17);                                                    
        FreeImage_Unload(dib_rocks_o17);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
