#ifdef WIN32 
void load_o7_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o7 = FreeImage_GetFileType(o7_FilePath, 0);                       
    dib_o7   = FreeImage_Load(fifmt_o7, o7_FilePath, 0);                    
    temp_o7  = dib_o7;                                                      
    dib_o7   = FreeImage_ConvertTo32Bits(temp_o7);                          
    FreeImage_Unload(temp_o7);                                            

    if( dib_o7 != NULL )                                                    
    {                                                                       
        pixels_o7 = (BYTE*)FreeImage_GetBits(dib_o7);                       
    }                                                                     

    o7_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o7_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o7 != NULL )                                                    
    {                                                                       
        free(pixels_o7);                                                    
        FreeImage_Unload(dib_o7);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
