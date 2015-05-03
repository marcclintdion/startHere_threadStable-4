#ifdef WIN32 
void load_o13_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o13 = FreeImage_GetFileType(o13_FilePath, 0);                       
    dib_o13   = FreeImage_Load(fifmt_o13, o13_FilePath, 0);                    
    temp_o13  = dib_o13;                                                      
    dib_o13   = FreeImage_ConvertTo32Bits(temp_o13);                          
    FreeImage_Unload(temp_o13);                                            

    if( dib_o13 != NULL )                                                    
    {                                                                       
        pixels_o13 = (BYTE*)FreeImage_GetBits(dib_o13);                       
    }                                                                     

    o13_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o13_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o13 != NULL )                                                    
    {                                                                       
        free(pixels_o13);                                                    
        FreeImage_Unload(dib_o13);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
