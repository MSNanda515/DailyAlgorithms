function drawGrid(horCells = 20, verCells = 20) {
    let i, j;
    gridObj = document.getElementById("main-grid");
    for (i = 0; i < verCells; i++) {
        for (j = 0; j < horCells; j++) {
            const block = document.createElement('div');
            block.classList.add('grid-item');
            block.innerHTML = i * 30 + j;
            gridObj.appendChild(block);
        }
    }
}