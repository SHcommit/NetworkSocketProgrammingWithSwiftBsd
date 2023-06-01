//
//  GroupView.swift
//  SoTalk
//
//  Created by 양승현 on 2023/05/30.
//

import UIKit

extension GroupView {
  enum Constant {
    static let itemSize = CGSize(width: 250, height: 375)
    static let edgeInset = 50.0
    static let interLineSpacing = 50.0
  }
}

final class GroupView: UICollectionView {
  // MARK: - Initialization
  private override init(frame: CGRect, collectionViewLayout layout: UICollectionViewLayout) {
    super.init(frame: frame, collectionViewLayout: layout)
  }
  
  required init?(coder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
  
  convenience init() {
    let layout = UICollectionViewFlowLayout()
    layout.scrollDirection = .horizontal
    layout.itemSize = Constant.itemSize
    self.init(frame: .zero, collectionViewLayout: layout)
    translatesAutoresizingMaskIntoConstraints = false
    backgroundColor = .none
    decelerationRate = .fast
    contentInset = UIEdgeInsets(top: 0, left: 50, bottom: 0, right: 50)
    showsHorizontalScrollIndicator = false
    self.register(
      GroupViewCell.self,
      forCellWithReuseIdentifier: GroupViewCell.id)
  }
}
