#ifdef WIN32 
void load_o11_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o11 = FreeImage_GetFileType(o11_FilePath, 0);                       
    dib_o11   = FreeImage_Load(fifmt_o11, o11_FilePath, 0);                    
    temp_o11  = dib_o11;                                                      
    dib_o11   = FreeImage_ConvertTo32Bits(temp_o11);                          
    FreeImage_Unload(temp_o11);                                            

    if( dib_o11 != NULL )                                                    
    {                                                                       
        pixels_o11 = (BYTE*)FreeImage_GetBits(dib_o11);                       
    }                                                                     

    o11_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o11_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o11 != NULL )                                                    
    {                                                                       
        free(pixels_o11);                                                    
        FreeImage_Unload(dib_o11);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
