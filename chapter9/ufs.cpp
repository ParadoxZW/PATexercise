int findFather(int v) {
    if (v == father[v]) return v;
    else {
        int F = findFather(father[v]);
        father[v] = F;
        return F;
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}