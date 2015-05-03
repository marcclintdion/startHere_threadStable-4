#ifdef WIN32 
void load_o14_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o14 = FreeImage_GetFileType(o14_FilePath, 0);                       
    dib_o14   = FreeImage_Load(fifmt_o14, o14_FilePath, 0);                    
    temp_o14  = dib_o14;                                                      
    dib_o14   = FreeImage_ConvertTo32Bits(temp_o14);                          
    FreeImage_Unload(temp_o14);                                            

    if( dib_o14 != NULL )                                                    
    {                                                                       
        pixels_o14 = (BYTE*)FreeImage_GetBits(dib_o14);                       
    }                                                                     

    o14_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o14_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o14 != NULL )                                                    
    {                                                                       
        free(pixels_o14);                                                    
        FreeImage_Unload(dib_o14);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
