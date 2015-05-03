#ifdef WIN32 
void load_o21_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o21 = FreeImage_GetFileType(o21_FilePath, 0);                       
    dib_o21   = FreeImage_Load(fifmt_o21, o21_FilePath, 0);                    
    temp_o21  = dib_o21;                                                      
    dib_o21   = FreeImage_ConvertTo32Bits(temp_o21);                          
    FreeImage_Unload(temp_o21);                                            

    if( dib_o21 != NULL )                                                    
    {                                                                       
        pixels_o21 = (BYTE*)FreeImage_GetBits(dib_o21);                       
    }                                                                     

    o21_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o21_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o21 != NULL )                                                    
    {                                                                       
        free(pixels_o21);                                                    
        FreeImage_Unload(dib_o21);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
