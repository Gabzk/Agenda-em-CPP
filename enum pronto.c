char *obterNomeContato ( enum tipoContato tpC );
char *obterNomeEndereco ( enum tipoEndereco tpEnd);
char *obterNomeRede ( enum tipoRede tpR );

char *obterNomeContato ( enum tipoContato tpC )
{
    const char *nomeContato[] =
    {
        "Comercial", "Fixo", "Pessoal", "Fax", "Personalizado"
    };

    return ( nomeContato [tpC]);
}

char *obterNomeEndereco ( enum tipoEndereco tpEnd)
{
    const char *nomeEndereco[] =
    {
        "Al.", "Av.", "Pr.", "R.", "Tr."
    };

    return ( nomeEndereco [tpEnd] );
}

char *obterNomeRede ( enum tipoRede tpR )
{
    const char *nomeRede[] =
    {
        "Instagram", "Facebook", "Twitter", "Linkedin", "Outros"
    };

    return ( nomeRede [tpR] );
}
