from dataclasses import dataclass

import matplotlib.pyplot as plt
import numpy as np


@dataclass
class Point:
    x: int
    y: int


def plot_matrix(matrix: np.ndarray):
    plt.imshow(matrix, cmap="binary", interpolation="nearest")
    plt.grid(True, color="gray", linewidth=0.5)

    rows, cols = matrix.shape
    plt.xticks(np.arange(-0.5, cols, 1), np.arange(0, cols + 1))
    plt.yticks(np.arange(-0.5, rows, 1), np.arange(rows, -1, -1))

    plt.savefig("plot.png")


def write_pixel(x: int, y: int, matrix: np.ndarray) -> None:
    height, width = matrix.shape
    if x > width - 1 or y > height - 1:
        raise ValueError("Index out of bound")

    converted_x = x
    converted_y = height - y - 1

    matrix[converted_y, converted_x] = 1


def bresenham(pi: Point, pf: Point, viewport: np.ndarray) -> None:
    dx = pf.x - pi.x
    dy = pf.y - pi.y

    d = 2 * dy - dx
    dE = 2 * dy
    dNE = 2 * (dy - dx)

    x = pi.x
    y = pi.y
    write_pixel(x, y, viewport)

    while x < pf.x:
        if d <= 0:
            d = d + dE
            x = x + 1
        else:
            d = d + dNE
            x = x + 1
            y = y + 1

        write_pixel(x, y, viewport)


def main():
    viewport = np.zeros((10, 10), dtype=np.uint8)
    bresenham(Point(1, 1), Point(8, 6), viewport)

    print(viewport)
    plot_matrix(viewport)


if __name__ == "__main__":
    main()
