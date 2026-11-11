from pathlib import Path
import shutil
import subprocess
import tempfile

root = Path(__file__).resolve().parent.parent
for nome in ('persistencia', 'cadastro'):
    with tempfile.TemporaryDirectory(prefix='jogoTeste') as tmp:
        pasta = Path(tmp)
        (pasta / 'perguntas').mkdir()
        shutil.copy(root / 'perguntas/perguntas.csv', pasta / 'perguntas/perguntas.csv')
        executavel = pasta / 'teste'
        subprocess.run(['cc', '-std=c11', '-Wall', '-Wextra', '-Wpedantic', '-I', str(root),
                        str(root / f'tests/{nome}.c'), str(root / 'perguntas/perguntas.c'),
                        '-o', str(executavel)], check=True)
        subprocess.run([str(executavel)], cwd=pasta, check=True)
