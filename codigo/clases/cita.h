
class Cita{
private:
    string fecha_;
    string hora_;
    
public:
    modificar(string fecha, string hora);
    anadir(string fecha, string hora);
    eliminar(string fecha, string hora);

    inline getFecha(){
        return fecha_;
    }
    inline getHora(){
        return hora_;
    }

    getFechaHora();
};